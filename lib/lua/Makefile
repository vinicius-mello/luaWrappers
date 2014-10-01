include ../make.inc

BASE = array$(EXT) pack$(EXT)
GRAPHICS = gl2$(EXT) glut$(EXT) tw$(EXT) cl$(EXT) glfw$(EXT)
NUMERIC = cubic$(EXT) sparse$(EXT) triplets$(EXT) lpt$(EXT) interval$(EXT) cloud$(EXT)\
		  blas$(EXT) lapack$(EXT) gsl$(EXT) vdb$(EXT) arpack$(EXT) umfpack$(EXT) lbfgsb$(EXT) ginac$(EXT)

TARGETS = $(BASE) $(GRAPHICS) $(NUMERIC)

all: $(BASE) $(GRAPHICS) $(NUMERIC)
base: $(BASE)
graphics: $(GRAPHICS)
numeric: $(NUMERIC)

array$(EXT): wrap/array_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB)

wrap/array_wrap.cxx: array.i $(MYLIB)/swig/array.i $(MYLIB)/wrappers/array.hpp
	swig -o $@ -c++ -lua $<

cloud$(EXT): wrap/cloud_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB)

wrap/cloud_wrap.cxx: $(MYLIB)/swig/cloud.i $(MYLIB)/wrappers/cloud.hpp
	swig -o $@ -c++ -lua $<

cubic$(EXT): wrap/cubic_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB)

wrap/cubic_wrap.cxx: $(MYLIB)/swig/cubic.i $(MYLIB)/wrappers/cubic.hpp
	swig -o $@ -c++ -lua $<

blas$(EXT): wrap/blas_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(BLAS_LIB) -I $(MYLIB)

wrap/blas_wrap.cxx: $(MYLIB)/swig/blas.i $(MYLIB)/wrappers/blas.hpp
	swig -o $@ -c++ -lua $<

lapack$(EXT): wrap/lapack_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(LAPACK_LIB) -I $(MYLIB)

wrap/lapack_wrap.cxx: $(MYLIB)/swig/lapack.i $(MYLIB)/wrappers/lapack.hpp
	swig -o $@ -c++ -lua $<

sparse$(EXT): wrap/sparse_wrap.cxx
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB) 

wrap/sparse_wrap.cxx: $(MYLIB)/swig/sparse.i $(MYLIB)/wrappers/sparse.hpp
	swig -o $@ -c++ -lua $<

triplets$(EXT): wrap/triplets_wrap.cxx
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB) 

wrap/triplets_wrap.cxx: $(MYLIB)/swig/triplets.i $(MYLIB)/wrappers/triplets.hpp
	swig -o $@ -c++ -lua $<

lpt$(EXT): wrap/lpt_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(LPT_LIB)  -I $(MYLIB)

wrap/lpt_wrap.cxx: $(MYLIB)/swig/lpt.i 
	swig -o $@ -c++ -lua $<

umfpack$(EXT): wrap/umfpack_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(UMFPACK_INC) $(LUA_LIB) $(UMFPACK_LIB) -I $(MYLIB)

wrap/umfpack_wrap.cxx: $(MYLIB)/swig/umfpack.i $(MYLIB)/wrappers/umfpack.hpp
	swig -o $@ -c++ -lua $<

arpack$(EXT): wrap/arpack_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(ARPACK_LIB)  -I $(MYLIB)

wrap/arpack_wrap.cxx: $(MYLIB)/swig/arpack.i $(MYLIB)/wrappers/arpack.hpp
	swig -o $@ -c++ -lua $<

ma57$(EXT): wrap/ma57_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(MA57_LIB)  -I $(MYLIB)

wrap/ma57_wrap.cxx: $(MYLIB)/swig/ma57.i $(MYLIB)/wrappers/ma57.hpp
	swig -o $@ -c++ -lua $<

ma47$(EXT): wrap/ma47_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) $(MA47_LIB)  -I $(MYLIB)

gl2$(EXT): wrap/gl2_wrap.cxx $(MYLIB)/wrappers/gl2.hpp  $(MYLIB)/wrappers/fbo.h 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(GL2_INC) $(LUA_LIB) $(GL2_LIB)  -I $(MYLIB)

wrap/gl2_wrap.cxx: $(MYLIB)/swig/gl2.i $(MYLIB)/wrappers/gl2.hpp  $(MYLIB)/wrappers/fbo.h 
	swig -o $@ -c++ -lua $<

glut$(EXT): wrap/glut_wrap.cxx $(MYLIB)/mytl/glut.hpp
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(GLUT_INC) $(LUA_LIB) $(GLUT_LIB)  -I $(MYLIB)

glfw$(EXT): glfw_wrapper.cpp
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(GLFW_INC) $(LUA_LIB) $(GLFW_LIB)

wrap/glut_wrap.cxx: $(MYLIB)/lua/glut.i $(MYLIB)/swig/glut.i $(MYLIB)/mytl/glut.hpp wrap/luaglut.cpp
	swig -o $@ -c++ -lua $<

tw$(EXT): wrap/tw_wrap.cxx $(MYLIB)/wrappers/tw.cpp
	c++ -o $@ $(SHARED) $< $(MYLIB)/wrappers/tw.cpp $(LUA_INC) $(TW_INC) $(LUA_LIB) $(TW_LIB)  -I $(MYLIB)

wrap/tw_wrap.cxx: $(MYLIB)/lua/tw.i $(MYLIB)/swig/tw.i $(MYLIB)/wrappers/tw.hpp wrap/luatw.cpp
	swig -o $@ -c++ -lua $<

cl$(EXT): wrap/cl_wrap.cxx $(MYLIB)/wrappers/cl.cpp
	c++ -o $@ $(SHARED) $< $(MYLIB)/wrappers/cl.cpp $(LUA_INC) $(CL_INC) $(LUA_LIB) $(CL_LIB)  -I $(MYLIB)

wrap/cl_wrap.cxx: $(MYLIB)/swig/cl.i $(MYLIB)/wrappers/cl.hpp 
	swig -o $@ -c++ -lua $<

gsl$(EXT): wrap/gsl_wrap.cxx
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(GSL_INC) $(LUA_LIB) $(GSL_LIB)  -I $(MYLIB)

wrap/gsl_wrap.cxx: gsl.i $(MYLIB)/swig/gsl.i wrap/luagsl.cpp $(MYLIB)/wrappers/gsl.hpp
	swig -o $@ -c++ -lua $<

vdb$(EXT): wrap/vdb_wrap.cxx
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(OPENVDB_INC) $(LUA_LIB) $(OPENVDB_LIB)  -I $(MYLIB)

wrap/vdb_wrap.cxx: $(MYLIB)/swig/vdb.i $(MYLIB)/wrappers/vdb.hpp
	swig -o $@ -c++ -lua $<

lbfgsb$(EXT): wrap/lbfgsb_wrap.cxx 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(LBFGSB_INC) $(LUA_LIB) $(LBFGSB_LIB)  -I $(MYLIB)

wrap/lbfgsb_wrap.cxx: $(MYLIB)/swig/lbfgsb.i $(MYLIB)/wrappers/lbfgsb.hpp
	swig -o $@ -c++ -lua $<

interval$(EXT): linterval.cpp 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(BOOST_INC) $(LUA_LIB) -I $(MYLIB)

pack$(EXT): lpack.c 
	cc -o $@ $(SHARED) $< $(LUA_INC) $(LUA_LIB) -I $(MYLIB)

ginac$(EXT): lginac.cpp 
	c++ -o $@ $(SHARED) $< $(LUA_INC) $(GINAC_INC) $(LUA_LIB) $(GINAC_LIB) -I $(MYLIB)

clean:
	rm -rf $(TARGETS) wrap/*_wrap.cxx
