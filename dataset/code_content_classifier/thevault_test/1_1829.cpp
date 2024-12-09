void DownloadManager::completed (TransferTask * task)
{
//  LOG_DEBUG ("%s Function-Entry",__FUNCTION__);

    if( !task ) {
        LOG_DEBUG ("%s: ERROR: task pointer lost or corrupted (Function-Exit-Early)",__FUNCTION__);
        return;
    }

    if (task->type == TransferTask::DOWNLOAD_TASK)
        completed_dl(task->p_downloadTask);
    if (task->type == TransferTask::UPLOAD_TASK)
        completed_ul(task->p_uploadTask);

    delete task;

//  LOG_DEBUG ("%s Function-Exit",__FUNCTION__);
}