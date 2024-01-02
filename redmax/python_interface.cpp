#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include "Mesh.h"

using namespace redmax;

namespace py = pybind11;

PYBIND11_MODULE(redmax_py, m) {
    // mesh
    py::class_<Mesh>(m, "Mesh");

    py::class_<SDFMesh, Mesh>(m, "SDFMesh")
        .def(py::init<Eigen::Matrix<double, 3, Eigen::Dynamic>, Eigen::Matrix<int, 3, Eigen::Dynamic>, dtype, std::string, std::string>(), 
                py::arg("V"), py::arg("F"), py::arg("dx"), py::arg("load_path") = "", py::arg("save_path") = "")
        .def_readwrite("vertices", &SDFMesh::_V)
        .def_readwrite("faces", &SDFMesh::_F)
        .def("clear_saved_sdf", &SDFMesh::clear_saved_SDF)
        .def("distance", &SDFMesh::distance,
                py::arg("X"))
        .def("min_distance", &SDFMesh::min_distance,
                py::arg("X"))
        .def("normal", &SDFMesh::normal, py::arg("x"));
        

    py::class_<BVHMesh, Mesh>(m, "BVHMesh")
        .def(py::init<Eigen::Matrix<double, 3, Eigen::Dynamic>, Eigen::Matrix<int, 3, Eigen::Dynamic>>(), 
                py::arg("V"), py::arg("F"))
        .def_readwrite("vertices", &SDFMesh::_V)
        .def_readwrite("faces", &SDFMesh::_F)
        .def("distance", &BVHMesh::distance,
                py::arg("X"))
        .def("min_distance", &BVHMesh::min_distance,
                py::arg("X"))
        .def("normal", &BVHMesh::normal, py::arg("x"));
}