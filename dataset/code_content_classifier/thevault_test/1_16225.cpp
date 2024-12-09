TEST(Minion,State_changes) { 
    Manager m;
    Minion elf;
    Minion goblin;
    std::vector<Minion*> _minions = {&elf,
                                    &goblin};

    Overlord ov(_minions);
    
    elf.set_target(make_tuple(2,2));
    goblin.set_target(make_tuple(30,30));

    m.schedule(ov, 100_ms)
     .schedule(elf, 100_ms)
     .schedule(goblin, 100_ms)
     .init()
     .start();

//start idle
EXPECT_EQ(elf.current().name(),"idle");//test idle
m.emit(Event("idle_select"));//emit check_idle
EXPECT_EQ(elf.current().name(),"idle");//test idle
elf.select();//select
m.emit(Event("idle_select"));//emit idle checck
EXPECT_EQ(elf.current().name(),"select");//test selected
m.emit(Event("select_travel"));//emit travel
EXPECT_EQ(elf.current().name(),"traveling");//test treaveling
elf.unselect();//unselcet
m.emit(Event("travel_select"));//emit travel sellect
EXPECT_EQ(elf.current().name(),"traveling");//test treaveling
m.emit(Event("travel_collide"));//emit colide
EXPECT_EQ(elf.current().name(),"traveling");//test traveling
elf.select_colide();//slect collide
m.emit(Event("travel_collide"));//emit collide
EXPECT_EQ(elf.current().name(),"colide");//test colide
m.emit(Event("collide_fight"));//emit emit fight
EXPECT_EQ(elf.current().name(),"fighting");//test fight

endwin();

    }