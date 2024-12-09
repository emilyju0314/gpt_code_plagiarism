void do_print_restore() {
  //if (job_recovery_commands_count > 0) return;
  memset(&print_restore_info, 0, sizeof(print_restore_info));
  //ZERO(job_recovery_commands);
  
  SERIAL_PROTOCOLLNPAIR("Print Restore Gcode file: ", CardReader::PrintRestoreGcodeFilename);
  
  if (!card.cardOK) card.initsd();

  if (card.cardOK) {

    #if ENABLED(DEBUG_PRINT_RESTORE)
      SERIAL_PROTOCOLLNPAIR("Init job recovery info. Size: ", (int) sizeof(print_restore_info));
    #endif

    if (card.printRestoreBinExists()) {
      print_restore_phase = BIN_FOUND;
      
      card.openPrintRestoreBin(true);
      card.loadPrintRestoreInfo();
      card.closePrintRestoreBin();
      // card.removePrintRestoreBin();

      #if ENABLED(DEBUG_PRINT_RESTORE)
        SERIAL_PROTOCOLLNPGM("Loaded print_restore_info");
        debug_print_job_recovery();
      #endif

      if (print_restore_info.valid_head && print_restore_info.valid_head == print_restore_info.valid_foot) {
        char cmd[40], temp[16];
        
        card.openFile(CardReader::PrintRestoreGcodeFilename, false);
        
        // Restore temperatures
        #if HAS_HEATED_BED
          // Restore the bed temperature
          sprintf_P(cmd, PSTR("M140 S%i"), print_restore_info.target_temperature_bed);
          card.write_command(cmd);
        #endif

        // Restore all hotend temperatures
        HOTEND_LOOP() {
          sprintf_P(cmd, PSTR("M104 S%i"), print_restore_info.target_temperature[e]);
          card.write_command(cmd);
        }

        // Wait for temperatures
        #if HAS_HEATED_BED
          // Wait for bed temperature
          sprintf_P(cmd, PSTR("M190 S%i"), print_restore_info.target_temperature_bed);
          card.write_command(cmd);
        #endif

        // Wait for all hotend temperatures
        HOTEND_LOOP() {
          sprintf_P(cmd, PSTR("M109 S%i"), print_restore_info.target_temperature[e]);
          card.write_command(cmd);
        }

        // Restore print cooling fan speeds
        for (uint8_t i = 0; i < FAN_COUNT; i++) {
          sprintf_P(cmd, PSTR("M106 P%i S%i"), i, print_restore_info.fanSpeeds[i]);
          card.write_command(cmd);
        }
        
        // show message
        sprintf_P(cmd, PSTR("M117 Restarting %s"), print_restore_info.sd_filename);
        card.write_command(cmd);
          
        #if HAS_LEVELING
          // Leveling off before G92 or G28
          strcpy_P(cmd, PSTR("M420 S0 Z0"));            
          card.write_command(cmd);
        #endif
        
        // Home axes
        strcpy_P(cmd, PSTR("G28"));
        card.write_command(cmd);
        
        #if HAS_LEVELING
          // Leveling on
          strcpy_P(cmd, PSTR("M420 S1"));               
          card.write_command(cmd);
        #endif
        
        // go to Z + 5 mm
        fmtSaveLine(cmd, PSTR("G1 Z%s"), ftostr33s, print_restore_info.current_position[Z_AXIS] + 5);
        card.write_command(cmd);
        
        // set extruder position to zero
        strcpy_P(cmd, PSTR("G92 E0"));
        card.write_command(cmd);
        
        // extrude 5 mm
        strcpy_P(cmd, PSTR("G1 F200 E5"));
        card.write_command(cmd);
        
        // set extruder position to 5 mm
        strcpy_P(cmd, PSTR("G92 F200 E5"));
        card.write_command(cmd);
        
        // set extruder position to restored position
        fmtSaveLine(cmd, PSTR("G92 E%s"), ftostr53s, print_restore_info.current_position[E_AXIS]);
        card.write_command(cmd);
        
        // restore X axis
        fmtSaveLine(cmd, PSTR("G1 F1200 X%s"), ftostr33s, print_restore_info.current_position[X_AXIS]);
        card.write_command(cmd);
        
        // restore Y axis
        fmtSaveLine(cmd, PSTR("G1 Y%s"), ftostr33s, print_restore_info.current_position[Y_AXIS]);
        card.write_command(cmd);
        
        // restore Z axis
        fmtSaveLine(cmd, PSTR("G1 Z%s"), ftostr33s, print_restore_info.current_position[Z_AXIS]);
        card.write_command(cmd);

        // restore feedrate
        fmtSaveLine(cmd, PSTR("M220 S%s"), ftostr33s, print_restore_info.feedrate_percentage);
        card.write_command(cmd);

        // restore babystep
        // #if ENABLED(BABYSTEPPING)
        // 	if (print_restore_info.babystep != 0) {
        // 		fmtSaveLine(cmd, PSTR("M290 Z%s"), ftostr33s, print_restore_info.babystep);
        // 		card.write_command(cmd);
        // 	}
        // #endif
        
        // buffered commands
        uint8_t r = print_restore_info.cmd_queue_index_r;
        while (print_restore_info.commands_in_queue) {
          strcpy(cmd, print_restore_info.command_queue[r]);
          card.write_command(cmd);
          
          print_restore_info.commands_in_queue--;
          r = (r + 1) % BUFSIZE;
        }
        
        // select original file
        sprintf_P(cmd, PSTR("M23 %s"), print_restore_info.sd_filename);
        card.write_command(cmd);
        
        // set file offset
        sprintf_P(cmd, PSTR("M26 S%lu"), print_restore_info.sdpos);
        card.write_command(cmd);
        
        // start print
        strcpy_P(cmd, PSTR("M24"));
        card.write_command(cmd);
        
        // show print status
        strcpy_P(cmd, PSTR("M27"));
        card.write_command(cmd);
        
        card.closefile();
        
        print_restore_phase = FILE_MADE;	
        
        memset(&print_restore_info, 0, sizeof(print_restore_info));
        
        // feedrate_percentage = 100;
        
        return;
        
      } else {
        if (print_restore_info.valid_head != print_restore_info.valid_foot)
          LCD_ALERTMESSAGEPGM("INVALID RESTORE BIN");
        memset(&print_restore_info, 0, sizeof(print_restore_info));
      }
    }
  }
  
  print_restore_phase = IDLE;
}