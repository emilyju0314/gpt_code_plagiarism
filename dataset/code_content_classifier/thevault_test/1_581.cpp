millis_time_t SandTimer::millis() {
    const Real sim_clock = CSimulator::GetInstance().GetSimulationClock();
//    const Real sim_clock = 500;
    return (millis_time_t)(sim_clock * (1000.0f / ticks_per_sec_));
}