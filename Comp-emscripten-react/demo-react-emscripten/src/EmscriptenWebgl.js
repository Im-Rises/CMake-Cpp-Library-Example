import React from "react";
import {useRef, useState, useEffect} from "react";
import * as mywasm from "./emscripten-module/comp-emscripten-react.js";
import './EmscriptenWebgl.css'

const EmscriptenWebgl = () => {
    const [context, setContext] = useState(undefined);
    const canvasRef = useRef();

    useEffect(() => {
        let Module = {canvas: canvasRef.current};
        mywasm.default(Module).then((result) => setContext(result));
    }, []);

    // useEffect(() => console.log(context), [context]);

    useEffect(() => {

        window.addEventListener("resize", handleResize);

        handleResize();

        return () => {
            window.removeEventListener("resize", handleResize);
        };
    }, []);


    const handleResize = () => {
        const canvas = canvasRef.current;
        canvas.width = window.innerWidth;
        canvas.height = window.innerHeight;
    };

    return (
        <>
            <canvas className={'canvas-emc'} id="canvas" ref={canvasRef}></canvas>
        </>
    );
}

export default EmscriptenWebgl;
