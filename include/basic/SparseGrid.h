 /*************************************************************************
 * 
 *  [2017] - [2018] Automy Inc. 
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Automy Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Automy Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Automy Incorporated.
 */

#ifndef SRC_COMMON_SPARSEGRID_H_
#define SRC_COMMON_SPARSEGRID_H_

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

#endif /* SRC_COMMON_SPARSEGRID_H_ */
