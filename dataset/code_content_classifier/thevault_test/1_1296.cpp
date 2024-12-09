void opcontrol() {
	using namespace pros;
	/*
	Controller master(E_CONTROLLER_MASTER);
	Motor left_mtr(1);
	Motor right_mtr(2);
	while (true) {
		lcd::print(0, "%d %d %d", (lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		left_mtr = left;
		right_mtr = right;
		delay(20);
		*/
		// motor inits
		//drive
		Motor leftFront(9);
		Motor leftBack(2);
		Motor rightFront(3);
		Motor rightBack(7);
		// intake
		Motor leftIntake(5);
		Motor rightIntake(8);
		//arm
		//Motor arm(5);
		// angle adjuster (tray tilter)
		Motor angleAdjuster(6);

		//variable inits
		int vexRTCh1, vexRTCh2, vexRTCh4;
		while(true){
			//tank drive code
			/*
			left_wheels.move(master.get_analog(ANALOG_LEFT_Y));
			right_wheels.move(master.gt_analog(ANALOG_RIGHT_Y));
			*/
			// variable definitions
			vexRTCh2 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_Y);
			vexRTCh1 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X);
			vexRTCh4 = master.get_analog(controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_X);

			//intake = master.get_digital(controller_digital_e_t::E_CONTROLLER_DIGITAL_R1);
			//intakeMode = master.get_digital(controller_digital_e_t::E_CONTROLLER_DIGITAL_R2);

			//arcade drive code
			rightFront.move(vexRTCh2 - vexRTCh1 - vexRTCh4);
			rightBack.move(vexRTCh2 - vexRTCh1 + vexRTCh4);
			leftFront.move(vexRTCh2 + vexRTCh1 + vexRTCh4);
			leftBack.move(vexRTCh2 + vexRTCh1 - vexRTCh4);

			//intake Code
			intakeMove();

/*
			// intake toggle code
			if (intake == 1) intakeOn = !intakeOn;
			if (intakeMode == 1) intakeCCW = !intakeCCW;

			if (intakeOn) {
				if (intakeCCW) {
					intakeDir = 127;
				} else {
					intakeDir = -127;
				}
				leftIntake.move(intakeDir);
				rightIntake.move(intakeDir);
			}
			else {
				leftIntake.move(0);
				rightIntake.move(0);
			}
*/
			// important delay for multitasking of the brain and to avoid abnormailities.
			// std::cout << left_wheels.get_voltage()*0.010583 << std::endl;

			//angle adjuster
			tilter();
			delay(15);
		}

	}