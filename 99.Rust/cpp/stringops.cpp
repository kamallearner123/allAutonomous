#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
    std::stringstream ss,ss2,ss3;
    ss << "hello " << argv[1];
    ss2 << "hello " << argv[1];
    ss3 << "hello " << argv[1];
    const char *s = ss.str().c_str();
    const char *s2 = ss2.str().c_str();
    const char *s3 = ss3.str().c_str();
    std::cout << s3 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s << std::endl;
}
