// Copyright 2021 Lasar1k <alf.ivan2002@gmail.com>

#include <boost/lexical_cast.hpp>
#include <boost/log/utility/setup.hpp>
#include <thread>
#include <vector>
#include "HashSearcher.hpp"

void init()
{
  boost::log::add_file_log("Log.log");
  srand(time(nullptr));
  boost::log::add_console_log(std::cout);
}

int main(int argc, char* argv[])
{
  init();
  size_t count_of_threads = 0;
  if (argc >= 2)
  {
    count_of_threads = boost::lexical_cast<size_t>(argv[1]);
  } else {
    count_of_threads = std::thread::hardware_concurrency();
  }

  std::vector<std::thread> threads;
  threads.reserve(count_of_threads);

  for (size_t index = 0; index < count_of_threads; ++index)
  {
    threads.emplace_back(HashSearcher::SearchHash);
  }

  for (std::thread& thread : threads)
    {
    thread.join();
    }

  return 0;
}
