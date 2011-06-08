/*
 * QtDcmManager.h
 *
 *  Created on: 2 déc. 2009
 *      Author: Alexandre Abadie
 */

#ifndef QTDCMMANAGER_H_
#define QTDCMMANAGER_H_

#include <QtGui>
#include <QtNetwork>

class QtDcmServer;
class QtDcmPreferences;
class QtDcmFindScuSignalManager;
class QtDcmManagerPrivate;

/**
 * This class is in charge of the different process (dcm2nii), pacs query/retrieve (dcm4chee),
 * temporary directory creation and removing, PACS server settings.
 *
 */
class QtDcmManager : public QObject
{
    Q_OBJECT
    private:
        void
        generateCurrentSerieDir();

        void
        deleteCurrentSerieDir();

        /**
         * Create the temporary directory (/tmp/qtdcm on Unix) and the logging directory.
         * (/tmp/qtdcm/logs)
         */
        void
        createTemporaryDirs();

        /**
         * This method try to delete the temporary directory when closing the QtDcm widget
         * (Doesn't work for the moment)
         */
        void
        deleteTemporaryDirs();

        //    /**
        //     * This method parse and fill all the list with the result of C-FIND
        //     */
        //    void
        //    parseQueryResult( QString query );

    public:

        /**
         * Default constructor. Instantiate the internal pointers and create the temporary directory.
         */
        QtDcmManager();

        /**
         * Default constructor. Instantiate the internal pointers and create the temporary directory.
         * @param parent the parent widget (the qtdcm object)
         */
        QtDcmManager(QWidget * parent);

        /**
         * The default destructor
         */
        virtual
        ~QtDcmManager();

        /**
         * Find SCU with Dcmtk code
         */
        void
        findPatientsScu();

        void
        findStudiesScu(QString patientName);

        void
        findSeriesScu(QString patientName, QString studyDescription);

        void
        findImagesScu(QString uid);

        void
        foundPatient(QMap<QString, QString> infosMap);
        void
        foundStudy(QMap<QString, QString> infosMap);
        void
        foundSerie(QMap<QString, QString> infosMap);
        void
        foundImage(QMap<QString, QString> infosMap);

        void
        moveSelectedSeries();

        void
        getPreviewFromSelectedSerie(QString uid, int elementCount);

        void
        findPatientsDicomdir();

        void
        findStudiesDicomdir(QString patientName);

        void
        findSeriesDicomdir(QString patientName, QString studyDescription);

        void
        findImagesDicomdir(QString serieUID);

        void
        setPatientsTreeWidget(QTreeWidget * widget);

        void
        setStudiesTreeWidget(QTreeWidget * widget);

        void
        setSeriesTreeWidget(QTreeWidget * widget);

        void
        setProgressBar(QProgressBar * progress);

        /**
         * This method read the dicomdir file and populate the patient treewidget
         *
         */
        void
        loadDicomdir();

        /**
         * Convenience method that display error message in a QMessageBox window.
         *
         * @param message the error message to display
         */
        void
        displayErrorMessage(QString message);

        /**
         * Convenience method that display information message in a QMessageBox window.
         *
         * @param info the information message to display
         */
        void
        displayMessage(QString info);

        /**
         * Return the dicomdir absolute path name
         *
         * @return _dicomdir the dicomdir file name.
         */
        QString
        getDicomdir() const;

        /**
         * Set the dicomdir file name
         *
         * @param dicomdir the dicomdir file name
         */
        void
        setDicomdir(QString dicomdir);

        /**
         * Return the output directory where the current serie will be reconstructed
         *
         * @return _outputdir the output directory path
         */
        QString
        getOutputDirectory() const;

        /**
         * Set the output directory
         *
         * @param directory the output directory
         */
        void
        setOutputDirectory(QString directory);

        /**
         * Return the pointer to the QtDcmPreferences instance
         *
         * @return _preferences
         * @see QtDcmPreferences
         */
        QtDcmPreferences *
        getPreferences();

        QtDcmServer *
        getCurrentPacs();

        /**
         * Set the pointer to the QtDcmPreferences instance
         *
         * @param prefs
         * @see QtDcmPreferences
         */
        void
        setPreferences(QtDcmPreferences * prefs);

        void
        setCurrentPacs(int index);

        /**
         * Patient name getter
         *
         * @return _patientName as a QString
         */
        QString
        getPatientName();

        /**
         * Patient name setter
         *
         * @param patientName as a QString
         */
        void
        setPatientName(QString patientName);

        /**
         * Patient id getter
         *
         * @return _patientId as a QString
         */
        QString
        getPatientId();

        /**
         * Patient id setter
         *
         * @param patientId as a QString
         */
        void
        setPatientId(QString patientId);

        void
        setPatientSex(QString sex);

        /**
         * Serie description getter
         *
         * @return _serieDescription as a QString
         */
        QString
        getSerieDescription();

        /**
         * Serie description setter
         *
         * @param serieDescription as a QString
         */
        void
        setSerieDescription(QString serieDescription);

        /**
         * Study description getter
         *
         * @return _studyDescription as a QString
         */
        QString
        getStudyDescription();

        /**
         * Study description setter
         *
         * @param studyDescription as a QString
         */
        void
        setStudyDescription(QString studyDescription);

        /**
         * Study modality setter
         *
         * @param modality as a QString
         */
        void
        setModality(QString modality);

        /**
         * Study modality getter
         *
         * @return _modality as a QString
         */
        QString
        getModality();

        /**
         * Study date setter
         *
         * @param date as a QString
         */
        void
        setDate1(QString date);

        /**
         * Study date getter
         *
         * @return _date as a QString
         */
        QString
        getDate1();

        /**
         * Study date setter
         *
         * @param date as a QString
         */
        void
        setDate2(QString date);

        /**
         * Study date getter
         *
         * @return _date as a QString
         */
        QString
        getDate2();

        /**
         * Return the current patient list
         *
         * @return QList<QtDcmPatient *> the list of patient loaded
         * @see QtDcmPatient
         */
        //    QList<QtDcmPatient *>
        //    getPatients();

        void
        addSerieToImport(QString uid);

        void
        removeSerieToImport(QString uid);

        void
        clearSeriesToImport();

        int
        seriesToImportSize();

        /**
         * Call dcm2nii in a QProcess object to reconstruct the given list of images
         *
         * @param images
         */
        //    void
        //    importSeriesFromDicomdir();

        /**
         * Call dcm2nii in a QProcess object to reconstruct the given list of images
         *
         * @param images
         */
        //    void
        //    importSeriesFromPACS();

        /**
         * add patient in the list
         */
        void
        addPatient();

        /**
         * Mode getter
         */
        QString
        getMode();

        void
        setImagesList(QList<QString> images);

        QList<QImage>
        getListImages();

        void
        setSerieId(QString id);

        QString
        getCurrentSerieDirectory();

        void
        setSeriesToExport(QMap<QString, QList<QString> > seriesToExport);

        void
        setQuery(QByteArray query);

        void
        setPreviewImageUID(QString uid);

    public slots:
        void
        updateProgressBar(int i);
        void
        moveSeriesFinished();
        void
        makePreview(QString filename);

    private:
        QtDcmManagerPrivate *d;
};

#endif /* QTDCMMANAGER_H_ */
