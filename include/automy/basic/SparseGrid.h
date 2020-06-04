
#ifndef INCLUDE_AUTOMY_BASIC_SPARSEGRID_H_
#define INCLUDE_AUTOMY_BASIC_SPARSEGRID_H_

#include <automy/math/Vector2i.hpp>
#include <automy/math/Vector3i.hpp>

#include <automy/basic/matrix_hash.h>

#include <unordered_map>


namespace automy {
namespace basic {

template<typename T>
using SparseGrid2D = std::unordered_map<automy::math::Vector2i, T, matrix_hash<automy::math::Vector2i>>;

template<typename T>
using SparseGrid3D = std::unordered_map<automy::math::Vector3i, T, matrix_hash<automy::math::Vector3i>>;


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_SPARSEGRID_H_ */
