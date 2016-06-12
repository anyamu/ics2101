#include <iostream>
#include <string>
#include <numeric>
#include <utility> // std::make_pair(), std::pair<T1,T2>
#include <map>
#include <vector>
#include <cstring> // memset()
#include <cstdlib> // rand()
#include <ctime>   // time(0)
class Emoji{ //!NOTE: This is the flyweight
  char image[2304]; //48x48x8 icon grayscale bitmap
  std::string name;
  const int dimx = 48, dimy = 48;
  friend std::ostream&
  operator<<(std::ostream&, const Emoji&);
public:
  Emoji(std::string name) : name(name) {
    memset(image, 0, sizeof(image)/sizeof(char));
  }
  const char* getEmoji()const { return image; }
  std::string getName()const { return name; }
};
std::ostream&
operator<<(std::ostream& out, const Emoji& emoji){
  return out << "emoji << " << emoji.getName()
             << " >>";
}
class EmojiFactory{
public:
  static Emoji* getEmoji(const std::string& iname){
    std::map<std::string, std::pair<Emoji*, int> >::iterator cit;
    cit = emojis.find(iname);
    if(cit != emojis.end()){
      (cit->second).second++; // = (cit->second).second + 1;
      return (cit->second).first;
    }else
      emojis[iname] = std::make_pair(new Emoji(iname), 1);
    return emojis[iname].first;
  }
  friend std::ostream&
  operator<<(std::ostream&, const EmojiFactory&);
private:
  static std::map<std::string, std::pair<Emoji*, int> > emojis;
};
std::map<std::string, std::pair<Emoji*, int> > EmojiFactory::emojis;
std::ostream&
operator<<(std::ostream& out, const EmojiFactory& ifactory){
  out << "EmojiFactory << ";
  std::map<std::string, std::pair<Emoji*, int> >::const_iterator cit;
  cit = (ifactory.emojis).begin();
  while(cit != (ifactory.emojis).end()){
    out << "[ " << cit->first << " x " << (cit->second).second
        << " ] ";
    ++cit;
  }
  return out << ">>" << std::endl;
}
class EmojiUser{
protected:
  std::vector<Emoji*> emojis;
  enum{
    TOTAL_EMOJI_TYPES = 5
  };
  static std::string emojitypes[TOTAL_EMOJI_TYPES];
};
std::string EmojiUser::emojitypes[] = {"Friend", "Acquaintance",
                                   "Boy", "Girl", "Family"};
class ContactList : public EmojiUser{
public:
  ContactList(const int count){
    for(int i = 0, bias = 0; i < count; ++i, ++bias){
      //!NOTE: Friends dominate the contact list
      if(!(bias % 7) || !(bias % 5)){
        emojis.push_back(EmojiFactory::getEmoji(
                        emojitypes[0]));
        continue;
        //!NOTE: Followed by Family
      }else if(!(bias % 11) || !(bias % 13)){
        emojis.push_back(EmojiFactory::getEmoji(
                        emojitypes[4]));
        continue;
      }
      emojis.push_back(EmojiFactory::getEmoji(
                      emojitypes[rand() % TOTAL_EMOJI_TYPES]));
    }
  }
};
using namespace std;
int main(){
  srand(time(0));
  //Create a contact list with 200 items that have Emoji
  ContactList list(200);
  cout << *(new EmojiFactory);
}
