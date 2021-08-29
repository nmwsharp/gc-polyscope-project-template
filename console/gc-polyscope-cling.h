#pragma cling add_include_path("../deps/geometry-central/include/")
#pragma cling add_include_path("../deps/polyscope/include/")
#pragma cling add_include_path("../deps/polyscope/deps/glm/")
#pragma cling add_include_path("../deps/polyscope/deps/imgui/imgui/")
#pragma cling add_include_path("/usr/local/include/eigen3/")
#pragma cling add_library_path("../build/lib/")
#pragma cling load( "libgeometry-central.dylib" )
#pragma cling load( "libpolyscope.dylib" )

#include <geometrycentral/surface/manifold_surface_mesh.h>
#include <geometrycentral/surface/meshio.h>
#include <geometrycentral/surface/vertex_position_geometry.h>

#include "polyscope/polyscope.h"
#include "polyscope/surface_mesh.h"
polyscope::SurfaceMesh *psMesh;

using namespace geometrycentral;
using namespace geometrycentral::surface;

std::unique_ptr<ManifoldSurfaceMesh> mesh;
std::unique_ptr<VertexPositionGeometry> geometry;

void load_mesh( std::string filename ) {
   std::cout << "Loading " << filename << " into 'mesh' and 'geometry'..." << std::endl;
   std::tie(mesh, geometry) = readManifoldSurfaceMesh( filename.c_str() );
}

void init_view() {
   // Initialize Polyscope
   std::cout << "Initializing Polyscope..." << std::endl;
   polyscope::init();
   std::cout << "Registering mesh as 'psMesh'..." << std::endl;
   // Register the mesh with Polyscope
   psMesh = polyscope::registerSurfaceMesh(
         "mesh",
         geometry->inputVertexPositions, mesh->getFaceVertexList(),
         polyscopePermutations(*mesh));
}

void view() {
   // Update the vertex positions
   psMesh->updateVertexPositions( geometry->inputVertexPositions );

   // Give control to the Polyscope GUI
   polyscope::show();
}

