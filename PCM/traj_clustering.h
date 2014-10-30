#ifndef _TRAJ_CLUSTERING_H
#define _TRAJ_CLUSTERING_H

#include "sample_set.h"
#include <QThread>

class TrajClusteringThread : public QThread
{
	Q_OBJECT

public:
	void run() Q_DECL_OVERRIDE;

signals:
	void finish_compute();


};


#endif
