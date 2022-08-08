message(STATUS "Enter Mesh folder")
set(MODULE_MESH Mesh)
aux_source_directory(. DIR_MESH_SRC)

add_library(Mesh SHARED ${DIR_MESH_SRC})

target_link_libraries(Mesh "-lfmt")
target_link_libraries(Mesh Qt6::Core)
target_link_libraries(Mesh Eigen3::Eigen)

message(STATUS "Leave Mesh folder\n")