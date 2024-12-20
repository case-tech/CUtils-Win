// The MIT License(MIT)
// Copyright © 2024 Case Technologies

#include "Common.hpp"

namespace CUtils
{
   class Random 
   {
   public:
      Random();
      int RandomInt(int min, int max);
      double RandomDouble(double min, double max);
      double NormalDouble(double mean, double stddev);
      int BinomialInt(int t, double p);
      bool BernoulliBool(double p);
      int PoissonInt(double mean);

   private:
      std::mt19937 generator;
   };
}
