// The MIT License(MIT)
// Copyright © 2024 Case Technologies 

#pragma once
#include "Common.hpp"

namespace CUtils
{
   class Multithread 
   {
   public:
      Multithread() = default;
      ~Multithread();

      template<typename Callable, typename... Args>
      void AddTask(Callable&& func, Args&&... args)
      {
         tasks.push_back(std::bind(std::forward<Callable>(func), std::forward<Args>(args)...));
      }

      void Run();
      void JoinAll();
      void JoinOne(std::thread& t);
      void CancelAll();

   private:
      std::vector<std::thread> threads;  
      std::vector<std::function<void()>> tasks; 
   };
}

