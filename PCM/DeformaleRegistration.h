#ifndef  _DEFORMABLEREGISTRATION_H
#define  _DEFORMABLEREGISTRATION_H

#include <QThread>
#include "tracer.h"
#include "sample_set.h"
#include <set>

struct LifeSpan
{
	IndexType  start;
	IndexType  end; 
};
struct PCloudTraj 
{
	PCloudTraj(){}
	PCloudTraj(IndexType _start,IndexType _end,vector<IndexType> _trajNode)
	{
		trajLifeSpan.start    = _start;
		trajLifeSpan.end      = _end;
		trajNode = _trajNode;
	}
	LifeSpan           trajLifeSpan;
	vector<IndexType>  trajNode;
};

struct PCloudModel
{
	PCloudModel(){}
	LifeSpan  modeLifeSpan;
	vector<Matrix33> fNode;//rigid motion
	vector<Matrix33> bNode;
	Matrix3X         Centers;
};

class DeformableRegistration :public QThread
{
	Q_OBJECT

public:
	void run() Q_DECL_OVERRIDE;
public:
	DeformableRegistration();
	~DeformableRegistration(){};
public:
       signals:
	     void finish_compute();

public:

public:
	void   estimateCorrespondence(Sample &srGraph,Sample & tgGraph,MatrixXXi & res_cor);
	ScalarType avgDistancePoint(IndexType pointIndex,Sample & smp,IndexType neigNum,Matrix3X & dst,Vec3 & mean);
	ScalarType totalDistance(Sample &smp,IndexType neigNum,Matrix3X & dst);
	IndexType   findMinCorr(PointType & srPoint,Vec3& mean, int * neigIndex,Sample & smp);
	void   calculateRestPos(Sample& srGraph,Sample& tgGraph,MatrixXXi & vtx_cor,Matrix3X & restPos);
	void   getNeigCoorByIndex(Sample & smp,vector<IndexType> & neigIndex,Matrix3X & res_coor);
	void   updateCoor(PointType& srpoint,Matrix3X & srNeigCoor,Matrix3X & tgNeigCoor);
	void   getCorNeigIndex(IndexType * srNeigIndex,IndexType * tgNeigIndex,MatrixXXi & corMat);
	void   combinationCoor(ScalarType stiffCoff,Sample & srGraph,Sample & trGraph,Matrix3X & restPos,MatrixXXi& vtx_cor);
	void   combinationCoor(ScalarType stiffCoff,Sample & srGraph,Sample & trGraph,
		                   Matrix3X & restPos,MatrixXXi& vtx_cor,MatrixXX& isDeformable,std::set<IndexType> & distLrgIndex);
	void   updateCooByTPS(Sample & srCloud,Matrix3X & oriCoor,Sample & srGraph,Sample& tgGraph);
	void   calculateMapFunction(Matrix3X & orisrGraphCoor,Sample& srGraph,IndexType axisIndex, Matrix3X & res_mapFunc);
	void   interpolateCoordinate(Sample & srCloud,Matrix3X & mapFunctionCoff,Sample& tgGraph);
	void   constructUpperMat(MatrixXX & upperMat,Matrix3X & oriCoor/*Matrix3X & distanceField*/,Sample & srGraph,IndexType axisIndex);
	void   sloveLinearSysByLU(MatrixXX & LeftMat,MatrixXX & RightMat,Matrix3X& res_mapFunc,IndexType axisIndex);
	ScalarType  tpsRBF(ScalarType radius);
	void   loaclICP(Sample & srGraph,Sample& tgGraph,MatrixXXi & vtx_cor,Matrix3X& restPos);
	void   localICP(Sample & srGraph,Sample& tgGraph,MatrixXXi & vtx_cor,
		            Matrix3X& restPos,MatrixXX& isDeformable); 
	void   optimizeCoor(Sample&srGraph,Sample&tgGraph,MatrixXXi & vtx_cor);

	//processing real data
public:
	void calculateTrajFrature(MatrixXX & featureMat);//record trajectory feature
	void point2point(Matrix3X & srCloud,Matrix3X & tgCloud,Matrix33 & rotMat);
	void non_rigidRegister(Sample& srGraph,Sample& tgGraph,MatrixXXi & vtxMap,
		                   MatrixXX & isDeformbale,std::set<IndexType> & distLrgIndex);
	void intersectionCorrespondence(IndexType * srLoaclNeig,IndexType * tgLoaclNeig,MatrixXXi & vtx_map,
		                            vector<IndexType> & srInterRes,vector<IndexType> & tgInterRes);
	void intersectionCorrespondenceInverse(IndexType * srLoaclNeig,IndexType * tgLoaclNeig,MatrixXXi & vtx_map,
		vector<IndexType> & srInterRes,vector<IndexType> & tgInterRes);
	void getConstantNeigCoorByIndex(Sample & smp,IndexType * neigIndex,Matrix3X & res_coor);
	void calculateNeigDis(Matrix3X & neigCoor,VecX& resDis);
	ScalarType deformableValue(VecX& srNeigDis,VecX & resNeigDis);
	void calculateTrajEndIndex(MatrixXXi & TrajBeginIndex,MatrixXXi& globalCor2Frame,MatrixXXi& trajEndIndex);
	void initFrontVtxMap(MatrixXXi& frontVtxMap,IndexType trajNum);
	void alignTargetCoor(Matrix3X & tgCloud,MatrixXXi & vertexMap);
	IndexType recordCorIndex(MatrixXXi & glb_cor,std::set<IndexType> recordCorSet);

	// in order to clustering
	void calculateLifeSpansTraj(vector<PCloudTraj> & totalTraj,IndexType LifeMin);
	void drawLifespansTraj(vector<PCloudTraj> & lifeSpans);
	void makeCorrespondenceOne2One(MatrixXXi& globalMap,MatrixXX& deformableValue,IndexType tgVtxNum);
	PCloudModel constrcutRigidMotionMode(vector<PCloudTraj> & oriTraj,LifeSpan & comTime);

	//Index the node coordinate
	void getTrajNodeCoordinate(PCloudTraj & traj,IndexType frameIndex,PointType & resCoor);

	//get the traj nodes coordinate no the same frame
	void getMultiTrajNodeCoordinate(vector<PCloudTraj>& multiTraj,IndexType frameId,Matrix3X &resCoorMat);

	// get the affine transformation from srPCloud to tgPCloud--using least squares
	void calculateTransformation2PClouds(Matrix3X & srPCoud,Matrix3X & tgPCloud,Matrix33 & transMat);

	// rand produce 3 traj from total tajs
	bool sample3validTraj(vector<PCloudTraj> & totTraj,vector<PCloudTraj>& resTraj,LifeSpan & lifesp);

	// get the trajs  common time
	bool getCommonTime(vector<PCloudTraj> & eleTraj,LifeSpan & lifesp);

	// arbitraily traj and arbitraily model 's distance ,if no commontime then distance is infinty
	ScalarType traj2ModlDistance(PCloudTraj& traj, PCloudModel& model);

	//get a subset of the traj with comTime
	void intersectionTrajWithComTime(PCloudTraj & oriTraj,LifeSpan & comTime,PCloudTraj & newTraj);

	// get a subset of the motion model  with comTime
	void intersectionModelWithComTime(PCloudModel & oriModel,LifeSpan & comTime,PCloudModel & newModel);

	// get the smallest distance between traj and model
	ScalarType minTraj2ModelDis(PCloudTraj& traj, PCloudModel& model,LifeSpan & comTime);

	//give a point from a traj and produce a  new traj under a motin model
	void calNewTrajUnderModel(IndexType nodeId,PCloudModel & model,PointType oriNodePos,MatrixXX & rowNewTraj);

	// total test calculate pmodel
	void testingcalPmodel();

	// rand produce three valid trajs and calculate motion model with common time
	bool sampleModel(vector<PCloudTraj>& oriTraj,vector<PCloudModel>& smpOriModel,IndexType modelNum);

	//rand produce K motion models
	bool sampleModelByNeig(vector<PCloudTraj>& oriTraj,vector<PCloudModel>& smpOriModel,IndexType modelNum);

	// a  traj produce a motion model and the life-span is the same
	PCloudModel constructRigidMotionByNeig(PCloudTraj & oriTraj);

	// calculate the distance between a traj and a model
	void staticDistance(vector<PCloudTraj>& oritrj,vector<PCloudModel>& oriModel);

	//test J-linkage cluster

	// produce a dream traj set
	void produceDreamTraj(vector<PCloudTraj>& resTraj);

	//calculate center
	void calculateCenter(Matrix3X& oriCoordinate,Eigen::Vector3f& mean);

	void calculateFixedLengthTraj( vector<PCloudTraj>& trajs, IndexType smp_idx,IndexType length );
	void DeformableRegistration::calculateTrajFeature(vector<PCloudTraj>& oriTraj,IndexType trajLen,MatrixXX& featureMat);
public:	
	//visualization used by testing---
	void visNeigVertex(Sample& oriCloud,VecX& vtxIndex);
	void updateLocalCoordinate(Sample& oriCloud,Matrix3X& vtxCoor,VecX& vtxIndex);

private:
	SampleSet & m_smpSet;
	IndexType m_neigNum;
};
#endif