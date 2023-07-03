#include "include/config.h"
#include "include/point.h"

int main(int num, char **kind){
    auto config = random_ply::Config(num, kind);
    if ( !config.Check() ) std::logic_error("Missing argument\n");

    random_ply::CreatePLY(config);
}