class Base{
  int priv;
protected:
  int prot;
public:
  int publ;
};
// What can derived1 access from Base?
// What are the access specifiers of members inherited from Base?
class derived1 : Base {
  int priv1;
protected:
  int prot1;
public:
  int publ1;
};
// What can derived2 access from derived1?
// What are the access specifiers of members inherited  from derived1?
// What about the inherited members of Base in derived1?
class derived2 : public derived1 {
  int priv2;
protected:
  int prot2;
public:
  int publ2;
};
// What can derived3 access from derived2?
// What are the access specifiers of members inherited from derived2?
// What about the inherited members of Base & derived1 in derived2?
class derived3 : protected derived2 {
  int priv3;
protected:
  int prot3;
public:
  int publ3;
};
// Assignment: write out all the remaining inheritance
//             schemes that are possible together with all possible
//             member access specifiers. Upload your code to your
//             github account.
