#ifndef GRID_HPP
#define GRID_HPP

#include <CL/cl.hpp>
#include <vector>


//void CreateGrid(const std::vector<Sphere> &objects, size_t resolution, std::vector<cl_uint> &indices, std::vector<CellData> &cells);
void CreateGrid(const std::vector<Triangle> &objects, size_t resolution, std::vector<cl_uint> &indices, std::vector<CellData> &cells);

#endif // GRID_HPP
