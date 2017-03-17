#include "include/Socio.hpp"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
int main(){
Socio *s1=new Socio("1234","abcd");
cout<<s1->getCI()<<endl;
cout<<s1->getnombre()<<endl;

return (0);
}
