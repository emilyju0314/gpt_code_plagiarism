void covarianceN(vectorn& mean, matrixn& c, const matrixn& a) 
	{
		mean.aggregateEachColumn(CAggregate::AVG, a);

		matrixn zeroMeaned;
		zeroMeaned.setSize(a.rows(), a.cols());
		for (int i=0;i<a.rows();i++)
			zeroMeaned.row(i).sub(a.row(i), mean);

		//zeroMeaned.each2(&vectorn::sub, a, mean);
	//	m::each2(	zeroMeaned, &vectorn::sub, a, mean);

		int dimension=a.cols();
		m_real numData=a.rows();

		c.setSize(dimension, dimension);

		for(int i=0; i<dimension; i++)
		{
			for(int j=0; j<dimension; j++)
			{
				// 곱한거의 average
				c[i][j]=(zeroMeaned.column(i)%zeroMeaned.column(j));///(numData);
			}
		}
	}