const fs = require("fs");

var functions = {
    "GXSetBlendMode": null,
    "GXBegin": null,
    "GXSetVtxAttrFmt": null,
    "GXLoadPosMtxImm": null,
    "GXSetNumIndStages": null,
    "GXSetTevDirect": null,
    "GXSetAlphaCompare": null,
    "GXSetZMode": null,
    "GXSetTevOp": null,
    "GXSetNumChans": null,
    "GXSetNumTevStages": null,
    "GXSetNumTexGens": null,
    "GXSetTevOrder": null,
    "GXSetTevColorIn": null,
    "GXSetTevAlphaIn": null,
    "GXSetTevColorOp": null,
    "GXSetTevAlphaOp": null,
    "GXSetCullMode": null,
    "GXLoadTexMtxImm": null,
    "GXSetChanCtrl": null,
    "GXSetCurrentMtx": null,
    "GXSetTexCoordGen2": null,
    "GXSetLineWidth": null,
    "GXClearVtxDesc": null,
    "GXSetVtxDesc": null,
    "GXInitTexObj": null,
    "GXLoadTexObj": null,
    "GXInvalidateTexAll": null,
    "GXSetProjection": null,
    "GXSetScissor": null,
    "GXGetScissor": null
};

/** @param {string} framework */
function parseAddresses(framework) {
    framework.split("\n").forEach((line) => {
        var split = line.split(/\s+/).slice(1);
        var address = split[2];
        var name = split[4];
        if (functions[name] !== undefined) {
            if (functions[name] !== null) {
                console.error("Redefining existing addresss");
            }
            functions[name] = "0x" + address.toUpperCase();
        }
    });

    var output = "";
    for (var name of Object.keys(functions)) {
        output += `#define ${name}_addr ${functions[name]}\n`;
    }

    fs.writeFile("tmp/out.json", JSON.stringify(functions, null, 2), (err) => console.error(err));
    fs.writeFile("tmp/out.h", new Buffer(output), (err) => console.error(err));
}

fs.readFile("frameworkF.map", (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    parseAddresses(data.toString());
})