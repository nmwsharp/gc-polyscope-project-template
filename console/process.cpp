void process()
{
   load_mesh( "spot.obj" );
   init_view();

   FaceData<double> data( *mesh );
   for( Face f : mesh->faces() ) {
      data[f] = geometry->faceArea(f);
   }
   psMesh->addFaceScalarQuantity( "area", data );

   view();
}

