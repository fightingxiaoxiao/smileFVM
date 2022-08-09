message(STATUS "Configure Mesh")
set(MODULE_MESH Mesh)
aux_source_directory(. DIR_MESH_SRC)

add_library(Mesh SHARED ${DIR_MESH_SRC})

include_directories(${Python3_INCLUDE_DIRS})

target_link_libraries(Mesh "-lfmt")
target_link_libraries(Mesh Qt6::Core)
#target_link_libraries(Mesh Eigen3::Eigen)
target_link_libraries(Mesh ${Python3_LIBRARIES})
