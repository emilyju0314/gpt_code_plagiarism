void ArduboyPlaytune::step()
{
  byte command, opcode, chan;

  while (1) {
    command = pgm_read_byte(score_cursor++);
    opcode = command & 0xf0;
    chan = command & 0x0f;
    if (opcode == TUNE_OP_STOPNOTE) { /* stop note */
      Serial.println("Stop note");
      stopNote(chan);
    }
    else if (opcode == TUNE_OP_PLAYNOTE) { /* play note */
      Serial.println("Play note");
      all_muted = !outputEnabled();
      playNote(chan, pgm_read_byte(score_cursor++));
    }
    else if (opcode < 0x80) { /* wait count in msec. */
      duration = ((unsigned)command << 8) | (pgm_read_byte(score_cursor++));
      Serial.print("Wait "); Serial.println(duration);
      break;
    }
    else if (opcode == TUNE_OP_RESTART) { /* restart score */
      Serial.println("Restart score");
      score_cursor = score_start;
    }
    else if (opcode == TUNE_OP_STOP) { /* stop score */
      Serial.println("Stop score");
      tune_playing = false;
      break;
    }
  }
}