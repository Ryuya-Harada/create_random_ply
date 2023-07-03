#include "include/config.h"
#include "include/point.h"

int main(int num, char **kind){
    auto config = random_ply::Config(num, kind);
    if ( !config.Check() ) std::logic_error("Missing argument\n");

    if ( config.color ){
        auto color = random_ply::Color(config);
        color.CreatePLY();
    }else {
        auto mono = random_ply::Mono(config);
        mono.CreatePLY();
    }
}