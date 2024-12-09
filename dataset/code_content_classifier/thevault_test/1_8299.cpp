void apply_change() {

	solver.setSolverMode(sph_solverType);
	solver.setGravity(vec2(0, sph_gravity));
	solver.setD0(sph_d0);
	solver.setA(sph_a);
	solver.setG(sph_g);
	solver.setB(sph_B);
	solver.setE(sph_e);
	solver.setWS(sph_ws);
	solver.setH(sph_h);
	solver.setMass(sph_m);
	solver.apply_change();
}