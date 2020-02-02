const fs = require("fs");

var functions = ["__GXDefaultTexRegionCallback",
    "__GXDefaultTlutRegionCallback",
    "__GXShutdown",
    "__GXInitRevisionBits",
    "GXInit",
    "__GXInitGX",
    "GXCPInterruptHandler",
    "GXInitFifoBase",
    "GXInitFifoPtrs",
    "GXInitFifoLimits",
    "GXSetCPUFifo",
    "GXSetGPFifo",
    "GXSaveCPUFifo",
    "__GXSaveCPUFifoAux",
    "GXGetGPStatus",
    "GXGetFifoBase",
    "GXGetFifoSize",
    "GXSetBreakPtCallback",
    "__GXFifoInit",
    "__GXFifoReadEnable",
    "__GXFifoReadDisable",
    "__GXFifoLink",
    "__GXWriteFifoIntEnable",
    "__GXWriteFifoIntReset",
    "__GXCleanGPFifo",
    "GXSetCurrentGXThread",
    "GXGetCurrentGXThread",
    "GXGetCPUFifo",
    "GXGetGPFifo",
    "GXSetVtxDesc",
    "GXSetVtxDescv",
    "__GXSetVCD",
    "__GXCalculateVLim",
    "GXClearVtxDesc",
    "GXSetVtxAttrFmt",
    "GXSetVtxAttrFmtv",
    "__GXSetVAT",
    "GXSetArray",
    "GXInvalidateVtxCache",
    "GXSetTexCoordGen2",
    "GXSetNumTexGens",
    "GXSetMisc",
    "GXFlush",
    "__GXAbort",
    "GXAbortFrame",
    "GXSetDrawDone",
    "GXDrawDone",
    "GXPixModeSync",
    "GXPokeAlphaMode",
    "GXPokeAlphaRead",
    "GXPokeAlphaUpdate",
    "GXPokeBlendMode",
    "GXPokeColorUpdate",
    "GXPokeDstAlpha",
    "GXPokeDither",
    "GXPokeZMode",
    "GXPeekZ",
    "GXSetDrawSyncCallback",
    "GXTokenInterruptHandler",
    "GXSetDrawDoneCallback",
    "GXFinishInterruptHandler",
    "__GXPEInit",
    "__GXSetDirtyState",
    "GXBegin",
    "__GXSendFlushPrim",
    "GXSetLineWidth",
    "GXSetPointSize",
    "GXEnableTexOffsets",
    "GXSetCullMode",
    "GXSetCoPlanar",
    "__GXSetGenMode",
    "GXSetDispCopySrc",
    "GXSetTexCopySrc",
    "GXSetDispCopyDst",
    "GXSetTexCopyDst",
    "GXSetDispCopyFrame2Field",
    "GXSetCopyClamp",
    "GXGetNumXfbLines",
    "GXGetYScaleFactor",
    "GXSetDispCopyYScale",
    "GXSetCopyClear",
    "GXSetCopyFilter",
    "GXSetDispCopyGamma",
    "GXCopyDisp",
    "GXCopyTex",
    "GXClearBoundingBox",
    "GXInitLightAttn",
    "GXInitLightSpot",
    "GXInitLightDistAttn",
    "GXInitLightPos",
    "GXInitLightDir",
    "GXInitLightColor",
    "GXLoadLightObjImm",
    "GXSetChanAmbColor",
    "GXSetChanMatColor",
    "GXSetNumChans",
    "GXSetChanCtrl",
    "GXGetTexBufferSize",
    "__GetImageTileCount",
    "GXInitTexObj",
    "GXInitTexObjCI",
    "GXInitTexObjLOD",
    "GXGetTexObjWidth",
    "GXGetTexObjHeight",
    "GXGetTexObjFmt",
    "GXGetTexObjWrapS",
    "GXGetTexObjWrapT",
    "GXGetTexObjMipMap",
    "GXGetTexObjTlut",
    "GXLoadTexObjPreLoaded",
    "GXLoadTexObj",
    "GXInitTlutObj",
    "GXLoadTlut",
    "GXInitTexCacheRegion",
    "GXInitTlutRegion",
    "GXInvalidateTexAll",
    "GXSetTexRegionCallback",
    "GXSetTlutRegionCallback",
    "GXSetTexCoordScaleManually",
    "__SetSURegs",
    "__GXSetSUTexRegs",
    "__GXSetTmemConfig",
    "GXSetTevIndirect",
    "GXSetIndTexMtx",
    "GXSetIndTexCoordScale",
    "GXSetIndTexOrder",
    "GXSetNumIndStages",
    "GXSetTevDirect",
    "__GXUpdateBPMask",
    "__GXSetIndirectMask",
    "__GXFlushTextureState",
    "GXSetTevOp",
    "GXSetTevColorIn",
    "GXSetTevAlphaIn",
    "GXSetTevColorOp",
    "GXSetTevAlphaOp",
    "GXSetTevColor",
    "GXSetTevColorS10",
    "GXSetTevKColor",
    "GXSetTevKColorSel",
    "GXSetTevKAlphaSel",
    "GXSetTevSwapMode",
    "GXSetTevSwapModeTable",
    "GXSetAlphaCompare",
    "GXSetZTexture",
    "GXSetTevOrder",
    "GXSetNumTevStages",
    "GXSetFog",
    "GXSetFogRangeAdj",
    "GXSetBlendMode",
    "GXSetColorUpdate",
    "GXSetAlphaUpdate",
    "GXSetZMode",
    "GXSetZCompLoc",
    "GXSetPixelFmt",
    "GXSetDither",
    "GXSetDstAlpha",
    "GXSetFieldMask",
    "GXSetFieldMode",
    "GXCallDisplayList",
    "GXProject",
    "GXSetProjection",
    "GXSetProjectionv",
    "GXGetProjectionv",
    "GXLoadPosMtxImm",
    "GXLoadNrmMtxImm",
    "GXSetCurrentMtx",
    "GXLoadTexMtxImm",
    "__GXSetViewport",
    "GXSetViewport",
    "GXGetViewportv",
    "GXSetScissor",
    "GXGetScissor",
    "GXSetScissorBoxOffset",
    "GXSetClipMode",
    "__GXSetMatrixIndex",
    "GXSetGPMetric",
    "GXClearGPMetric",
    "GXReadXfRasMetric"
];


/**
 * @param {string} header 
 */
function parseHeader(header) {
    var headerFunctions = {};
    var typedefs = "\n\n// TypeDefinitions\n";
    var structs = "// Structs\n";
    var inStruct = false;
    header.split("\n").forEach((_line) => {
        var line = _line.trim();
        var defSplit = line.split(" ");
        if (line.endsWith(";") && defSplit[1].startsWith("GX_")) {
            var functiondef = defSplit[1].slice(0, defSplit[1].indexOf("(")).replace("_", "");
            headerFunctions[functiondef] = line.trim();
        } else if (inStruct || line.startsWith("typedef struct")) {
            inStruct = true;
            if (line.endsWith("{")) {
                structs += line + "\n";
            } else if (_line.startsWith("\t") || _line.startsWith(" ")) {
                structs += "    " + replaceTypes(line.slice(0, line.indexOf(";") + 1)) + "\n";
            } else if (line.startsWith("}") && line.indexOf(";") != -1) {
                structs += line.slice(0, line.indexOf(";") + 1) + "\n";
                inStruct = false;
            } else {
                console.log("unknown: " + line);
                inStruct = false;
            }
        } else if (line.startsWith("typedef") && line.endsWith(";")) {
            typedefs += replaceTypes(line.trim()) + "\n";
        }
    });

    var notFound = [];
    var found = [];

    var output = "\n\n// Function Pointers\n";
    var output2 = "\n\n// Defines\n";
    for (var fn of functions) {
        if (headerFunctions[fn] === undefined) {
            notFound.push(fn);
        } else {
            var fp = toFunctionPointer(fn, headerFunctions[fn]);
            output += fp.typedef;
            output2 += fp.ifstatement;
            found.push(headerFunctions[fn]);
        }
    }

    fs.writeFile("tmp/out.json", JSON.stringify({ notFound, found }, null, 2), (err) => console.error(err));
    fs.writeFile("tmp/out.h", new Buffer(structs + typedefs + output + output2), (err) => console.error(err));
}

function toFunctionPointer(linkName, functionDef) {
    var defSplit = functionDef.trim().split(" ");
    var returnType = replaceTypes(defSplit[0]);
    var parameters = functionDef.slice(functionDef.indexOf("("));
    parameters = replaceTypes(parameters);
    var funcName = defSplit[1].slice(0, defSplit[1].indexOf("("));

    var typedef = `typedef ${returnType} (*${linkName}_t)${parameters}\n`;
    var ifstatement = `#ifdef ${linkName}_addr\n`;
    ifstatement += `#define ${funcName} ((${linkName}_t)(${linkName}_addr))\n`;
    ifstatement += `#endif\n`;
    return { typedef, ifstatement };
}

function replaceTypes(_in) {
    return _in.replace(/u8/g, "uint8_t")
        .replace(/u16/g, "uint16_t")
        .replace(/u32/g, "uint32_t")
        .replace(/u64/g, "uint64_t")
        .replace(/s8/g, "int8_t")
        .replace(/s16/g, "int16_t")
        .replace(/s32/g, "int32_t")
        .replace(/s64/g, "int64_t")
        .replace(/f32/g, "float")
        .replace(/f64/g, "double");
}

fs.readFile("gx.h", (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    parseHeader(data.toString());
});