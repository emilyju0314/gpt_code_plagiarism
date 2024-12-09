TYPED_TEST(SpatialTransformerLayerTest, TestThetaGradient) {
        typedef typename TypeParam::Dtype Dtype;
        FillerParameter filler_param;
        filler_param.set_min(-1);
        filler_param.set_max(1);
        UniformFiller<Dtype> filler(filler_param);
        filler.Fill(this->blob_theta_);
        LayerParameter layer_param;
        SpatialTransformerLayer<Dtype> layer(layer_param);
        // call backward to generate theta_gradient
        layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
        layer.Forward(this->blob_bottom_vec_, this->blob_top_vec_);
        for (int i = 0; i < this->blob_top_->count(); ++i) {
            this->blob_top_->mutable_cpu_diff()[i] = (Dtype) 1.;
        }
        vector<bool> propagate_down(this->blob_bottom_vec_.size(), true);
        layer.Backward(this->blob_top_vec_, propagate_down,
                this->blob_bottom_vec_);
        // compute theta gradient using finite difference
        shared_ptr<Blob<Dtype> > ref_blob_theta_diff;
        ref_blob_theta_diff.reset(new Blob<Dtype>());
        ref_blob_theta_diff->ReshapeLike(*(this->blob_theta_));
        theta_gradient(this->blob_data_, this->blob_theta_, (double) 1e-4, ref_blob_theta_diff.get());
        const Dtype* theta_diff = this->blob_theta_->cpu_diff();
        const Dtype* ref_theta_diff = ref_blob_theta_diff->cpu_diff();
        for (int i = 0; i < this->blob_theta_->count(); ++i) {
            EXPECT_NEAR(theta_diff[i], ref_theta_diff[i], 1e-4) << "i=" << i;
        }
    }