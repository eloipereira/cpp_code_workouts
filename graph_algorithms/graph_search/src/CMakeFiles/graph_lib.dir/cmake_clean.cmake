file(REMOVE_RECURSE
  "libgraph_lib.pdb"
  "libgraph_lib.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/graph_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
