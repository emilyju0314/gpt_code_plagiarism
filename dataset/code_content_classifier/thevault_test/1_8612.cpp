sd::ops::DeclarableOp *OpRegistrator::getOperation(Nd4jLong hash) {
            if (!_declarablesLD.count(hash)) {
                if (!_msvc.count(hash)) {
                    nd4j_printf("Unknown D operation requested by hash: [%lld]\n", hash);
                    return nullptr;
                } else {
                    _locker.lock();

                    auto str = _msvc.at(hash);
                    auto op = _declarablesD.at(str);
                    auto oHash = op->getOpDescriptor()->getHash();

                    std::pair<Nd4jLong, sd::ops::DeclarableOp*> pair(oHash, op);
                    _declarablesLD.insert(pair);

                    _locker.unlock();
                }
            }

            return _declarablesLD.at(hash);
        }