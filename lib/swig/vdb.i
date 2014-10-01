%module vdb
%{
#include <wrappers/vdb.hpp>
%}

typedef unsigned int uint;

void initialize();

class signed_distance {
public:
	signed_distance(const array<float>& vtx, const array<uint>& idx, float res);
	double dist(double x, double y, double z);
	void write(char * filename);
	int fill_with_spheres(array<float> sph, float min, float max);
};
