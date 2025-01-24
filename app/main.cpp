#include <iostream>
#include <config.hpp>
#include <KMP.hpp>

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

    LPSArray("ABACABAB");

    return 0;
}