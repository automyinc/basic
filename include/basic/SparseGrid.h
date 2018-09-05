
#ifndef BASIC_INCLUDE_BASIC_SPARSEGRID_H_
#define BASIC_INCLUDE_BASIC_SPARSEGRID_H_

#include <math/Vector2i.h>
#include <math/Vector3i.h>

#include "matrix_hash.h"

#include <unordered_map>


namespace basic {

template<typename T>
using SparseGrid2D = std::unordered_map<math::Vector2i, T, matrix_hash<math::Vector2i>>;

template<typename T>
using SparseGrid3D = std::unordered_map<math::Vector3i, T, matrix_hash<math::Vector3i>>;


} // basic

#endif /* BASIC_INCLUDE_BASIC_SPARSEGRID_H_ */
