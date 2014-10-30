#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "paint_canvas.h"
#include "globals.h"
#include <string>
#include <map>
#include <QLabel>
#include "select_tool.h"

using namespace std;


class main_window : public QMainWindow
{
	Q_OBJECT

public:
	main_window(QWidget *parent = 0);
	~main_window();
	static std::string title() { return "[MainWindow]: "; }

	void showCoordinateAndIndexUnderMouse( const QPoint& point );

	void createTreeWidgetItems();

	public slots:
		bool openFile();
		bool openFiles();
		bool saveFiles();
		void selectedSampleChanged(QTreeWidgetItem * item, int column);

		bool setSampleVisible();
		bool setSampleInvisible();

		void doSpectralClustering();
		void finishClustering();

		void doTrajClustering();

		void openScanner();
		void closeScanner();

		void setObjectColorMode();
		void setVertexColorMode();
		void setLabelColorMode();

		void setSelectToolMode();
		void setSceneToolMode();
		void setNormalToolMode();

		void showTracer();
		void clearTracer();
		
		void showSelectedTrajectory();
		void computeSampleNormal();

private:
		void createAction();
		void createFileMenuAction();
		void createPaintSettingAction();
		void createAlgorithmAction();
		void createToolAction();

		void createStatusBar();
		void resetSampleSet();


private:

	//UI
	Ui::main_windowClass ui;
	PaintCanvas*		main_canvas_;

	QLabel*			coord_underMouse_label_;
	QLabel*			vtx_idx_underMouse_label_;

	//Samples Info
	vector< pair<string,string> >		cur_import_files_attr_;
	IndexType			cur_select_sample_idx_;
	IndexType			last_select_sample_idx_;

	Tool*			single_operate_tool_;


};


#endif // MAIN_WINDOW_H
