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

#ifndef SRC_COMMON_MATRIX_HASH_H_
#define SRC_COMMON_MATRIX_HASH_H_

#include <functional>


namespace basic {

// Hash function for Eigen matrix and vector.
// The code is from `hash_combine` function of the Boost library. See
// http://www.boost.org/doc/libs/1_55_0/doc/html/hash/reference.html#boost.hash_combine .
template<typename T>
struct matrix_hash : std::unary_function<T, size_t> {
	std::size_t operator()(T const& matrix) const {
		// Note that it is oblivious to the storage order of Eigen matrix (column- or
		// row-major). It will give you the same hash value for two different matrices if they
		// are the transpose of each other in different storage order.
		size_t seed = 0;
		for (size_t i = 0; i < matrix.size(); ++i) {
			seed ^= std::hash<typename T::Scalar>()(matrix[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};


} // basic

#endif /* SRC_COMMON_MATRIX_HASH_H_ */
