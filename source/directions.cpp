#pragma once
#include <iostream>

auto UP = std::make_pair(-1, 0);
auto DOWN = std::make_pair(1, 0);
auto LEFT = std::make_pair(0, -1);
auto RIGHT = std::make_pair(0, 1);
auto DiagnolUpL = std::make_pair(-1, -1);
auto DiagnolUpR = std::make_pair(-1, 1);
auto DiagnolDownL = std::make_pair(1, -1);
auto DiagnolDownR = std::make_pair(1, 1);