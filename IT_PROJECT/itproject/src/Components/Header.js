import React, { Component } from 'react';
import { Navbar, Nav, FormControl, Container, Form, Button } from 'react-bootstrap';
import logo from './logo192.png';
import { BrowserRouter, Routes, Route, Link } from 'react-router-dom';
import Home from '../Pages/Home.js';
import About from '../Pages/About.js';

export default class Header extends Component {
    render() {
        return (
           
            <div>

            <Navbar fixed="top" collapseOnSelect expend="sm" bg="dark" variant="dark">
                <Container>
                    <Navbar.Brand href="/">
                        <img
                            src={logo}
                            height="30"
                            width="30"
                            className="d-inline-block align-top"
                            alt="logo"
                        /> TrainLoc
                    </Navbar.Brand>
                    <Navbar.Toggle aria-controls="responsive-navbar-nav" />
                    <Navbar.Collapse id="responsive-navbar-nav">
                        <Nav className="mr-auto">
                            <Nav.Link href="/">Home</Nav.Link>
                            <Nav.Link href="/about">About us</Nav.Link>
                            <Nav.Link href="/contacts">Contacts</Nav.Link>
                            <Nav.Link href="/blog">Blog</Nav.Link>
                        </Nav>
                        <Form inline >
                            <FormControl
                                type="text"
                                placeholder="Search"
                                className="sm-2"
                                
                                />
                                <Button variant="outline-info">Button</Button>
                            </Form>
                            

                            
                    </Navbar.Collapse>
                    </Container>
                   

                </Navbar>
                <BrowserRouter>
                    <Routes>
                        <Route path="/" element={<Home />} />
                        <Route path="/about" element={<About />} />

                    </Routes>
                </BrowserRouter>

               
            </div>

            )
    }
}