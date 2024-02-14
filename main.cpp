#include <fmt/color.h>
#include <fmt/ranges.h>
#include <vector>

int main()
{
  fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) | fmt::emphasis::underline, "你好{}！\n", "世界");

  std::vector<std::vector<char>> matrix = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'}
  };

  fmt::println("{}", matrix);
  return 0;
}