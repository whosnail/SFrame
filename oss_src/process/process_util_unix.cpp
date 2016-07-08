/**
 * Copyright (C) 2016 Turi
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 */
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <process/process_util.hpp>
#include <cstdlib>

namespace graphlab {

size_t get_parent_pid() {
  return (size_t)getppid();
}

size_t get_my_pid() {
  return (size_t)getpid();
}

void wait_for_parent_exit(size_t parent_pid) {
  while(1) {
    sleep(1);
    if (parent_pid != 0 && kill(parent_pid, 0) == -1) {
      break;
    }
  }
}

bool is_process_running(size_t pid) {
  return (kill(pid, 0) == 0);
}

boost::optional<std::string> getenv_str(const char* variable_name) {
  char* val = std::getenv(variable_name);
  if (val == nullptr) {
    return boost::optional<std::string>();
  } else {
    return boost::optional<std::string>(std::string(val));
  }
}

} // namespace graphlab
