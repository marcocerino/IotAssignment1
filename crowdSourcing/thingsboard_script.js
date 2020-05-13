function compute_sd(x_array, y_array,z_array){
    var j;
    //l_sma = 1/win * sum(x_i+y_i+z_i)
    var l_sma = 0;
    for(j=0; j<4; j++){
        if(x_array[j] !== null,z_array[j]!== null,y_array[j] !== null){
            l_sma += x_array[j] + y_array[j] + z_array[j];
        }
     }
    l_sma /= 4;
    var sosd=0;
    //sosd = (sum(x_i+y_i+z_i - l_sma)^2 / win)^1/2
    for(j=0; j<4; j++){
        if(x_array[j] !== null,z_array[j] !== null,y_array[j] !== null){
            sosd += Math.pow(x_array[j] + y_array[j] + z_array[j] - l_sma,2);
        }
    }
    sosd /= 4;
    
    if(sosd<0.5)
        return "Still";
    
    else
        return "Moving";
}
function transform(x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4){
    var x=[x1,x2,x3,x4];
    var y=[y1,y2,y3,y4];
    var z=[z1,z2,z3,z4];
    msg.data=compute_sd(x,y,z);
}

transform(msg.data[0].x,msg.data[1].x,msg.data[2].x,msg.data[3].x,
        msg.data[0].y,msg.data[1].y,msg.data[2].y,msg.data[3].y,
        msg.data[0].z,msg.data[1].z,msg.data[2].z, msg.data[3].z)


return {msg: msg, metadata: metadata, msgType: msgType};