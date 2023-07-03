#pragma once
#ifndef _CONFIG_H
#define _CONFIG_H

#include <vector>
#include <string>
#include <random>

namespace random_ply{
    class Config
    {
    public:
        std::vector<int> coor{std::vector<int>(3)};
        bool color{false};
        int size;
        std::string file{"test.ply"};
        Config(const int& num, char **kind) noexcept {
            for (int i = 1; i < num; i++)
            {
                const std::string str = std::string(kind[i]);
                if ( str.substr(0, 2) == "-n" ) file = str.substr(str.find("=") + 1);
                else if ( str.substr(0, 2) == "-p" ) size = Convert(str);
                else if ( str.substr(0, 2) == "-w" ) coor[0] = Convert(str);
                else if ( str.substr(0, 2) == "-c" ) color = true;
                else if ( str.substr(0, 2) == "-x" ) coor[0] = Convert(str);
                else if ( str.substr(0, 2) == "-y" ) coor[1] = Convert(str);
                else if ( str.substr(0, 2) == "-z" ) coor[2] = Convert(str);
            }
        };
        bool Check(){
            if ( coor[0] == 0 || size == 0 ) return false;
            if ( file.empty() ) file = "test.ply"; 
            else if ( file.substr(file.rfind(".")) != ".ply" ) file += ".ply";
            for (int i = 1; i < coor.size(); i++)
                if ( coor[i] == 0 ) coor[i] = coor[0];
            return true;
        };
        const float Geom(const int& num) const { return Sample<float>(coor[num]); };
        const std::uint8_t Alt() const { return Sample<std::uint8_t>(256); };
    private:
        template<typename T>
        constexpr T Sample(const int& num) const { return static_cast<T>(rand() % num); };
        auto Convert(const std::string& str) noexcept -> int {
            const int m = std::stoi(str.substr(str.find("=") + 1));
            return std::clamp(m, 1, static_cast<int>(1e8));
        };
    };
}

#endif