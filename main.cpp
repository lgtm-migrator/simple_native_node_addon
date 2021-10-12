#include <iostream>
#include <string>
#include <unistd.h>

int main() {
    pid_t cPid = fork();

    if (cPid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (cPid > 0)
    {
        return cPid;
    }
    else
    {
      const char* arg_list[] = {"/usr/bin/node","/home/developer/simple_native_node_addon/index.js", nullptr};
      execve("/usr/bin/node", const_cast<char* const *>(arg_list), nullptr);
      perror("execve");
      exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
