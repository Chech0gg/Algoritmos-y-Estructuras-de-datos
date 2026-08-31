reg  = [0,1,1,1,0,1,1,1,0,1]
rachaact= 0 
mejorracha = 0
for dia in reg:
    if dia ==1:
        rachaact += 1
        if rachaact > mejorracha:
            mejorracha = rachaact
    else:
        rachaact = 0
print("La mayor racha de días consecutivos con lluvia es:", mejorracha)
