#ifndef WRAP_VDB_HPP
#define WRAP_VDB_HPP
#include "array.hpp"
#include <openvdb/openvdb.h>
#include <openvdb/tools/MeshToVolume.h>
#include <openvdb/tools/VolumeToSpheres.h>
#include <openvdb/tools/Interpolation.h>
#include <openvdb/io/File.h>

using namespace openvdb;
using namespace openvdb::io;

class signed_distance {
	FloatGrid::Ptr grid;
	FloatGrid::ConstAccessor * accessor;
	tools::GridSampler<FloatGrid::ConstAccessor, openvdb::tools::BoxSampler>
    * fastSampler;
public:
	signed_distance(const array<float>& vtx, const array<uint>& idx, float res) {
		std::vector<Vec3s> points;
    	std::vector<Vec3I> triangles;
    	for(int i=0;i<vtx.height();++i) {
    		Vec3s xyz(vtx.get(i,0), vtx.get(i,1), vtx.get(i,2));
    		points.push_back(xyz);
    	}
    	for(int i=0;i<idx.height();++i) {
    		Vec3I ijk(idx.get(i,0), idx.get(i,1), idx.get(i,2));
    		triangles.push_back(ijk);
    	}
		grid = openvdb::tools::meshToLevelSet<FloatGrid>(
        *math::Transform::createLinearTransform(res), points, triangles);
		accessor = new FloatGrid::ConstAccessor(grid->getConstAccessor());
		fastSampler = new openvdb::tools::GridSampler<FloatGrid::ConstAccessor, openvdb::tools::BoxSampler>(*accessor, grid->transform());
	}
	double dist(double x, double y, double z) const {
		return fastSampler->wsSample(Vec3R(x, y, z));
	}
	void write(char * filename) const {
		grid->setName(filename);
		MetaMap::Ptr meta(new MetaMap);
    	meta->insertMeta("author", StringMetadata("Einstein"));
    	meta->insertMeta("year", Int32Metadata(2009));

    	GridPtrVecPtr grids(new GridPtrVec);
    	grids->push_back(grid);

    	// Write grids and metadata out to a file.
    	{
        	io::File vdbfile(filename);
        	vdbfile.write(*grids, *meta);
    	}
    	meta.reset();
    	grids.reset();
	}
	int fill_with_spheres(array<float> sph, float min, float max) const {
		std::vector<Vec4s> ss;
		openvdb::tools::fillWithSpheres(*grid,ss,sph.height(),false,min,max);
		for(int i=0;i<ss.size();++i) {
			Vec4s xyzr=ss[i];
			sph.set(i,0,xyzr.x());
			sph.set(i,1,xyzr.y());
			sph.set(i,2,xyzr.z());
			sph.set(i,3,xyzr.w());
		}
		return ss.size();
	}
};

#endif // WRAP_VDB_HPP
