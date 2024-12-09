TYPED_TEST(SpatialTransformerLayerTest, TestDataGradient) {
        typedef typename TypeParam::Dtype Dtype;
        FillerParameter filler_param;
        filler_param.set_min(-1);
        filler_param.set_max(1);
        UniformFiller<Dtype> filler(filler_param);
        filler.Fill(this->blob_theta_);
        LayerParameter layer_param;
        SpatialTransformerLayer<Dtype> layer(layer_param);
        GradientChecker<Dtype> checker(1e-2, 1e-3);
        checker.CheckGradientExhaustive(&layer, this->blob_bottom_vec_,
                this->blob_top_vec_, 0);
    }