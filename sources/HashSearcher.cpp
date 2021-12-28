// Copyright 2021 Lasar1k <alf.ivan2002@gmail.com>

#include "HashSearcher.h"
#include <string>
#include <thread>

void HashSearcher::SearchHash()
  {
      static const std::string end_of_hash = "0000";
      while (true)
      {
          std::string random_string = std::to_string(std::rand());
          std::string random_hash_string =
          picosha2::hash256_hex_string(random_string);
          if (random_hash_string.substr(random_hash_string.size()
          - end_of_hash.size()) == end_of_hash)
          {
              BOOST_LOG_TRIVIAL(info) << "Found correct value '"
              << random_string
              << "' with hash '" << random_hash_string << "'";
          } else {
              BOOST_LOG_TRIVIAL(trace) << "Thread with ID: "
              << std::this_thread::get_id()
              << " || Current value '" << random_string
              << "' with hash '" << random_hash_string << "'";
          }
      }
}
