std::string MainTable::current_method(){
    if(this->ui->FIFOMethod->isChecked()){
        return "FIFO";
    }
    else if(this->ui->LIFOMethod->isChecked()){
        return "LIFO";
    }
    else if(this->ui->LRUMethod->isChecked()){
        return "LRU";
    }
    else if(this->ui->LFUMethod->isChecked()){
        return "LFU";
    }
    return "RANDOM";
}