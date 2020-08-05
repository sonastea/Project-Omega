#ifndef HEADER_H
#define HEADER_H

/* Core */
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <thread>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

/* SFML */
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

/**
  * Explicitly convert enum class scoped types to an integer with to_int(EditorMode type)
  */
template<typename T>
constexpr auto to_int(T enumerator) noexcept
{
    return static_cast<std::underlying_type_t<T>>(enumerator);
}

#endif