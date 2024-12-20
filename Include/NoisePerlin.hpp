// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    class NoisePerlin
    {
    public:
        NoisePerlin(unsigned int seed = 0);
        double Noise(double x, double y) const;

    private:
        double Fade(double t) const;
        double Lerp(double t, double a, double b) const;
        double Grad(int hash, double x, double y) const;

    private:
        static const int PERM_SIZE = 256;
        std::vector<int> permutation;
    };
}
