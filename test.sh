echo "launching make in srcs..."
make re
echo "compilation..."
clang -Wall -Wextra -Werror test.c libasm.a
