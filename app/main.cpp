#include <iostream>
#include <vector>
#include <config.hpp>
#include <KMP.hpp>

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

    testKMP();

    return 0;
}