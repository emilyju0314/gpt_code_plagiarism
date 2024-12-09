static style::CustomGeometrySource::Options convertCustomGeometrySourceOptions(jni::JNIEnv& env,
                                                                                   const jni::Object<>& options,
                                                                                   style::TileFunction fetchFn,
                                                                                   style::TileFunction cancelFn) {
        using namespace mbgl::style::conversion;
        if (!options) {
            return style::CustomGeometrySource::Options();
        }
        Error error;
        optional<style::CustomGeometrySource::Options> result = convert<style::CustomGeometrySource::Options>(Value(env, options), error);
        if (!result) {
            throw std::logic_error(error.message);
        }
        result->fetchTileFunction = fetchFn;
        result->cancelTileFunction = cancelFn;
        return *result;
    }